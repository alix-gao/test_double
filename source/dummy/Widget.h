#pragma once

class Widget {
public:
    Widget() : standardized(false) {}

    void setStandardized(bool standardized) {
        this->standardized = standardized;
    }

    bool isStandardized() const {
        return standardized;
    }

private:
    bool standardized;
};

