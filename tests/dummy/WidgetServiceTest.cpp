#include <gtest/gtest.h>
#include "dummy/Widget.h"
#include "dummy/WidgetDao.h"
#include "dummy/ManagerService.h"
#include "dummy/WidgetService.h"

/*
 * 注意：假设在本次测试中，我们想要测试的是 WidegtService 的 StrandardizeWidget1 方法。通过测试 Widget 最终是否被成功设置为 Standard 来完成测试
 *      在这个方法中，我们并没有使用 WidgetDao 类，但是在 Service 的构造器中却需要这个 Dao 类型。为了成功新建出这个 Service，那么这个没有用的 Dao
 *      类只需要被新建即可，因此我们认为这个 Dao 类就是一个 Dummy 类型的测试替身。
 */

TEST(WidgetServiceTest, should_set_standardized_successfully) {
    Widget widget;
    WidgetDao dummyWidgetDao;
    ManagerService manager(true);
    WidgetService widgetService(dummyWidgetDao, manager);

    widgetService.standardizeWidget(widget);

    bool standardized = widget.isStandardized();
    ASSERT_TRUE(standardized);
}
