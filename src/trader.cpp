// Copyright 2024 Siddhant S. Karki
#include <iostream>
#include "../include/trader.h"


using TradingEngine::Trader;
using TradingEngine::TraderException;

TraderException::TraderException(const std::string& message):
    message(message) {}

const char* TraderException::what() const noexcept {
    return message.c_str();
}

int Trader::id_counter = 0;

Trader::Trader()
    : name{""},
    id {id_counter++},
    orderFactory{nullptr},
    orderBook{nullptr} {}

Trader::Trader(const std::string& n)
        : name{n}
        , orderBook{nullptr}
        , orderFactory{nullptr}
        , id{id_counter++}
{
}

Trader::Trader(const std::string& n,
    const std::vector<Stock>& s, OrderFactory* o, OrderBook* b)
        : id{id_counter++}
        , name{n}
        , stocks{s}
        , orderFactory{o}
        , orderBook{b}
{
}

void Trader::buy(const TradingEngine::Stock& stock, int quantity) {
    try {
        if (orderFactory != nullptr && orderBook != nullptr) {
            std::shared_ptr<Order> order = this->orderFactory->createOrder(
                    this->id, stock.getPrice(), quantity);
            this->orders.push_back(order);
            if (order != nullptr) {
                this->orderBook->addOrder(order);
            }
        }
    } catch (const TraderException& e) {
        std::cerr << "Trader Exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Trader::sell(const TradingEngine::Stock& stock, int quantity) {
    try {
        if (orderFactory != nullptr && orderBook != nullptr) {
            std::shared_ptr<Order> order = this->orderFactory->createOrder(
                    this->id, -stock.getPrice(), quantity);
            this->orders.push_back(order);
            if (order != nullptr) {
                this->orderBook->addOrder(order);
            }
        }
    } catch (const TraderException& e) {
        std::cerr << "Trader Exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Trader::trade(double buyThres, double sellThres, int buyQ, int sellQ) {
    for (const Stock& stock : this->stocks) {
        if (stock.getPrice() < buyThres) {
            this->buy(stock, buyQ);
        } else if (stock.getPrice() > sellThres) {
            this->sell(stock, sellQ);
        }
    }
}

int Trader::getID() const {
    return id;
}

const std::vector<std::shared_ptr<TradingEngine::Order>>&
    Trader::getOrders() const {
    return this->orders;
}

void Trader::addStock(const Stock& s) {
    this->stocks.push_back(s);
}

std::vector<TradingEngine::Stock> Trader::getStocks() const {
    return stocks;
}

Trader::~Trader() {
    delete orderFactory;
    delete orderBook;
}
