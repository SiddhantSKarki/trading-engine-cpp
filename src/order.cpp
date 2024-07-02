// Copyright 2024 @ Siddhant S. Karki
#include <format>
#include <algorithm>
#include <stdexcept>
#include "../include/order.h"


using TradingEngine::Order;
using TradingEngine::OrderType;
using TradingEngine::MarketOrder;
using TradingEngine::LimitOrder;
using TradingEngine::OrderFactory;


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






