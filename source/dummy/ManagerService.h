#pragma once

class ManagerService {
public:
    ManagerService(bool active) : active(active) {}

    bool isActive() const {
        return active;
    }

private:
    bool active;
};

