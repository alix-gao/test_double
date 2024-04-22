#pragma once

#include "WidgetDao.h"
#include "ManagerService.h"
#include "Widget.h"

class WidgetService {
public:
    WidgetService(WidgetDao& widgetDao, ManagerService& manager) : widgetDao(widgetDao), manager(manager) {}

    void standardizeWidget(Widget& widget) {
        if (manager.isActive()) {
            widget.setStandardized(true);
        }
    }

    void createWidget(Widget widget) {
        // Since we just want to describe the meaning of dummy and just want to create test for standardizWidget method
        // So, we omit this method.
    }

private:
    WidgetDao& widgetDao;
    ManagerService& manager;
};
