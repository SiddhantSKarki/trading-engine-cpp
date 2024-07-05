// Copyright 2024 @Siddhant S. Karki
#ifndef STOCK_H_
#define STOCK_H_

#include <string>

namespace TradingEngine {

class Stock {
 public:
        Stock();
        Stock(double, const std::string&);
        void setPrice(double);
        void setName(const std::string&);
        double getPrice() const;
        std::string getName() const;
 private:
        double price;
        std::string name;
};

}  // namespace TradingEngine

#endif  // STOCK_H_
