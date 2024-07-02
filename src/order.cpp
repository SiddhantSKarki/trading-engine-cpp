// Copyright 2024 @ Siddhant S. Karki
#include <format>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include "../include/order.h"


using TradingEngine::Order;
using TradingEngine::OrderType;
using TradingEngine::MarketOrder;
using TradingEngine::LimitOrder;
using TradingEngine::OrderFactory;
using TradingEngine::MarketOrderFactory;
using TradingEngine::LimitOrderFactory;
using TradingEngine::OrderMatchingStrategy;
using TradingEngine::PriceTimeOrderMatchingStrategy;


Order::Order(int id, double p, int q) :
    trader_id{id},
    price{p},
    quantity{q}
{}

Order::~Order() {}

int Order::getTrader_id() const {
    return this->trader_id;
}

double Order::getPrice() const {
    return this->price;
}

int Order::getQuantity() const {
    return this->quantity;
}

std::time_t Order::getTimeStamp() const {
    return this->timestamp;
}

void Order::reduceQuantity(int amount) {
    if (amount > 0 && amount <= quantity) {
        quantity -= amount;
    } else {
        throw std::out_of_range {
            std::format("Amount: {:d} out of range", amount)
        };
    }
}

OrderType Order::getOrderType() const {
    return this->ordertype;
}

void Order::setOrderType(OrderType type) {
    this->ordertype = type;
}

std::string MarketOrder::getOrderTypeStr() const {
    return "Market Order";
}

std::string LimitOrder::getOrderTypeStr() const {
    return "Limit Order";
}

OrderFactory::~OrderFactory() {}


std::unique_ptr<Order> MarketOrderFactory::createOrder(int trader_id,
    double price, int quantity) {
        return std::make_unique<MarketOrder>(trader_id, price, quantity);
}

std::unique_ptr<Order> LimitOrderFactory::createOrder(int trader_id,
    double price, int quantity) {
        return std::make_unique<LimitOrder>(trader_id, price, quantity);
}

OrderMatchingStrategy::~OrderMatchingStrategy() {}

void PriceTimeOrderMatchingStrategy::matchOrders (
    std::vector<std::shared_ptr<Order>>& buyOrders, 
        std::vector<std::shared_ptr<Order>>& sellOrders) {
    std::vector<std::shared_ptr<Order>> matchOrders;
    for (auto sellOrder = sellOrders.begin();
        sellOrder != sellOrders.end(); ++sellOrder) {
        for (auto it = buyOrders.begin(); it != buyOrders.end();) {
            if ((*sellOrder)->getPrice() <= (*it)->getPrice()) {
                matchOrders.push_back(*it);
                it = buyOrders.erase(it);
            } else {
                ++it;
            }
        }
    }
    // Insert elements from matchOrders before the end
    buyOrders.insert(buyOrders.end(), matchOrders.begin(), matchOrders.end());
}






