#pragma once

#include <iostream>
#include <stdexcept>

class CustomerManagementSystem {
public:
    std::string getContactInformationOf(int customerId) {
        std::string phoneNumber = getPhoneNumber(customerId);
        std::string address = getAddress(customerId);

        return "Phone Number: " + phoneNumber + "\n" + "Address: " + address;
    }

protected:
    virtual std::string getAddress(int customerId) {
        throw std::runtime_error("Cannot search in Database");
    }

    virtual std::string getPhoneNumber(int customerId) {
        throw std::runtime_error("Cannot search in Database");
    }
};

