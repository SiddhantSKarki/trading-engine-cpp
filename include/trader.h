// Copyright 2024 @Siddhant S. Karki
#ifndef TRADER_H_
#define TRADER_H_

#include <string>
#include <vector>
#include <memory>
#include "./order.h"
#include "./orderBook.h"
#include "./stock.h"

namespace TradingEngine {

class TraderException : public std::exception {
 public:
        explicit TraderException(const std::string&);
        virtual const char* what() const noexcept;
 private:
        std::string message;
};

class Trader {
 public:
        Trader();
        explicit Trader(const std::string&);
        Trader(const std::string&, const std::vector<Stock>&,
            OrderFactory*, OrderBook*);
        void buy(const Stock&, int);
        void sell(const Stock&, int);
        void trade(double, double, int, int);
        int getID() const;
        const std::vector<std::shared_ptr<Order>>& getOrders() const;
        void addStock(const Stock&);
        std::vector<Stock> getStocks() const;
        ~Trader();
 private:
        static int id_counter;
        int id;
        std::string name;
        std::vector<Stock> stocks;
        OrderFactory* orderFactory;
        OrderBook* orderBook;
        std::vector<std::shared_ptr<Order>> orders;
};

}  // namespace TradingEngine

#endif  // TRADER_H_
