#pragma once

#include <iostream>
#include <map>
#include <stdexcept>

#include "Customer.h"
#include "fake/CustomerManagementSystem.h"

class FakeCustomerManagementSystem : public CustomerManagementSystem {
private:
    std::map<int, Customer> customerMap;

public:
    FakeCustomerManagementSystem(std::map<int, Customer> customerMap) : customerMap(customerMap) {}

protected:
    std::string getAddress(int customerId) override {
        auto it = customerMap.find(customerId);
        if (it != customerMap.end()) {
            return it->second.getAddress();
        } else {
            throw std::runtime_error("Customer not found");
        }
    }

    std::string getPhoneNumber(int customerId) override {
        auto it = customerMap.find(customerId);
        if (it != customerMap.end()) {
            return it->second.getPhoneNumber();
        } else {
            throw std::runtime_error("Customer not found");
        }
    }
};

