#pragma once

#include <string>

class Customer {
private:
    std::string phoneNumber;
    std::string address;

public:
    Customer() = default;

    Customer(const std::string& phoneNumber, const std::string& address)
        : phoneNumber(phoneNumber), address(address) {}

    std::string getAddress() const {
        return address;
    }

    std::string getPhoneNumber() const {
        return phoneNumber;
    }
};

