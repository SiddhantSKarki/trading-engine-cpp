// Copyright Siddhant S. Karki @2024
#include <format>
#include <iostream>
#include "../include/orderBook.h"

using TradingEngine::OrderBook;
using TradingEngine::OrderType;


OrderBook::OrderBook(): strategy(nullptr) {}

void OrderBook::addOrder(std::shared_ptr<Order> order) {
    this->book.push_back(order);
}

void OrderBook::matchOrders() {
    std::vector<std::shared_ptr<Order>> buyOrders;
    std::vector<std::shared_ptr<Order>> sellOrders;

    for (const auto& order : book) {
        if (order->getPrice() > 0) {
            buyOrders.push_back(std::static_pointer_cast<Order>(order));
        } else {
            sellOrders.push_back(std::static_pointer_cast<Order>(order));
        }
    }

    strategy->matchOrders(buyOrders, sellOrders);

    this->book.clear();
    book.insert(book.end(), buyOrders.begin(), buyOrders.end());
    book.insert(book.end(), sellOrders.begin(), sellOrders.end());
}

void OrderBook::printOrderBook() const {
    std::cout << "Order Book Content.....\n";
    std::cout << std::format("|{:>6}|{:>10}|{:>10}|{:>5}|\n",
        "ID", "Price", "Quantity", "Order Type");
    for (const auto& order : book) {
        std::string orderTypeName =
            (order->getOrderType() == OrderType::BUY) ? "Buy" : "Sell";
        std::cout << std::format("{:>6d}|{:>10f}|{:>10d}|{:>5}",
            order->getTrader_id(), order->getPrice(),
            order->getQuantity(), orderTypeName);
    }
    std::cout << "\n";
}

void OrderBook::setStrategy(OrderMatchingStrategy* s) {
    strategy = s;
}
