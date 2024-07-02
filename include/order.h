#ifndef ORDER_H_
// Copyright @ 2024 Siddhant S. Karki
#define ORDER_H_

#include <memory>
#include <string>
#include <vector>
#include <ctime>

namespace TradingEngine {

    enum OrderType {
        BUY = 0,
        SELL = 1
    };

class Order {
 public:
        Order(int id, double price, int quantity);
        virtual ~Order();  // Destructor
        virtual std::string getOrderTypeStr() const = 0;
        int getTrader_id() const;
        double getPrice() const;
        int getQuantity() const;
        std::time_t getTimeStamp() const;
        void reduceQuantity(int);
        OrderType getOrderType() const;
        void setOrderType(OrderType);

 private:
        int trader_id;
        double price;
        int quantity;
        std::time_t timestamp;
        OrderType ordertype;
};

class MarketOrder : public Order {
 public:
        MarketOrder(int trader_id, double price, int quantity) :
            Order(trader_id, price, quantity) {}
        // Overriding the base class' getOrderStypeString
        std::string getOrderTypeStr() const override;
};

class LimitOrder : public Order {
 public:
        LimitOrder(int trader_id, double price, int quantity):
            Order(trader_id, price, quantity) {}
        std::string getOrderTypeStr() const override;
};

class OrderFactory {
 public:
        virtual std::unique_ptr<Order> createOrder(int, double, int) = 0;
        virtual ~OrderFactory();
};

class MarketOrderFactory : public OrderFactory {}





}  // namespace TradingEngine



#endif  // ORDER_H_
