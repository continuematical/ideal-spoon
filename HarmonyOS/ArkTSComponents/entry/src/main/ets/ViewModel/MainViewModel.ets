import defaultAppManager from '@ohos.bundle.defaultAppManager';
import PageResource from '../common/beans/ItemData';

export class MainViewModel {
  getSwiperImages(): Array<Resource> {
    let swipeImages: Resource[] = [
    $r('app.media.fig1'),
    $r('app.media.fig2'),
    $r('app.media.fig3'),
    $r('app.media.fig4')
    ];
    return swipeImages;
  }

  getFirstGridData(): Array<PageResource> {
    let firstGridData: PageResource[] = [
      new PageResource($r('app.string.my_love'), $r('app.media.love')),
      new PageResource($r('app.string.history_record'), $r('app.media.record')),
      new PageResource($r('app.string.message'), $r('app.media.message')),
      new PageResource($r('app.string.shopping_cart'), $r('app.media.shopping')),
      new PageResource($r('app.string.my_goal'), $r('app.media.target')),
      new PageResource($r('app.string.group'), $r('app.media.circle')),
      new PageResource($r('app.string.favorites'), $r('app.media.favorite')),
      new PageResource($r('app.string.recycle_bin'), $r('app.media.recycle'))
    ];
    return firstGridData;
  }

  getSecondGridData(): Array<PageResource> {
    let secondGridData: PageResource[] = [
      new PageResource($r('app.string.mainPage_top'), $r('app.media.top'), $r('app.string.mainPage_text_top')),
      new PageResource($r('app.string.mainPage_new'), $r('app.media.new'), $r('app.string.mainPage_text_new')),
      new PageResource($r('app.string.mainPage_brand'), $r('app.media.brand'), $r('app.string.mainPage_text_brand')),
      new PageResource($r('app.string.mainPage_found'), $r('app.media.found'), $r('app.string.mainPage_text_found'))
    ];
    return secondGridData;
  }

  getSettingListData(): Array<PageResource> {
    let settingListData: PageResource[] = [
      new PageResource($r('app.string.setting_list_news'), $r("app.media.news"), $r("app.string.setting_toggle")),
      new PageResource($r('app.string.setting_list_data'), $r("app.media.data"), null),
      new PageResource($r('app.string.setting_list_menu'), $r("app.media.menu"), null),
      new PageResource($r('app.string.setting_list_about'), $r("app.media.about"), null),
      new PageResource($r('app.string.setting_list_storage'), $r("app.media.storage"), null),
      new PageResource($r('app.string.setting_list_privacy'), $r("app.media.privacy"), null)
    ];
    return settingListData;
  }
}

export default new MainViewModel();