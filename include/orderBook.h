// Copyright 2024 Siddhant S. Karki
#ifndef ORDERBOOK_H_
#define ORDERBOOK_H_

#include <vector>
#include <memory>
#include "./order.h"

namespace TradingEngine {

class OrderBook {
 public:
        OrderBook();
        void addOrder(std::shared_ptr<Order>);
        void matchOrders();
        void printOrderBook() const;
        void setStrategy(OrderMatchingStrategy*);
 private:
        std::vector<std::shared_ptr<Order>> book;
        OrderMatchingStrategy* strategy;
};

}  // namespace TradingEngine


#endif  // ORDERBOOK_H_
