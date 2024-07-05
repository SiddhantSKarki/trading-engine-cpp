// Copyright 2024 Siddhant S. Karki
#include "../include/stock.h"

TradingEngine::Stock::Stock() = default;

TradingEngine::Stock::Stock(double price,
    const std::string& name) :
    price(price),
    name(name) {}

void TradingEngine::Stock::setName(const std::string& n) {
    this->name = n;
}

void TradingEngine::Stock::setPrice(double price) {
    this->price = price;
}

double TradingEngine::Stock::getPrice() const {
    return this->price;
}

std::string TradingEngine::Stock::getName() const {
    return this->name;
}
