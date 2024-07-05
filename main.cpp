// Copyright 2024 @Siddhnat S. Karki
#include <iostream>
#include "./include/order.h"


int main() {
    TradingEngine::MarketOrderFactory mkorderF{};
    std::unique_ptr<TradingEngine::Order> mkOrder
        {mkorderF.createOrder(101, 43.3, 3)};
    std::cout << mkOrder->getOrderTypeStr() << std::endl;
    return 0;
}