import CommonConstants from '../common/constants/CommonConstants'
import Home from '../View/Home';
import Settings from '../View/Settings';

@Entry
@Component
struct MainPage {
  @State currentIndex: number = CommonConstants.HOME_TAB_INDEX;
  private tabsController: TabsController = new TabsController();

  @Builder TabBuilder(title: string, index: number, selectedImg: Resource, normalImg: Resource) {
    Column() {
      Image(this.currentIndex == index ? selectedImg : normalImg)
        .width($r('app.float.mainPage_baseTab_size'))
        .height($r('app.float.mainPage_baseTab_size'))
    }
    .justifyContent(FlexAlign.Center)
    .height($r('app.float.mainPage_barHeight'))
    .width(CommonConstants.FULL_PARENT)
    .onClick(() => {
      this.currentIndex = index;
      this.tabsController.changeIndex(this.currentIndex);
    })
  }

  build() {
    Tabs({ barPosition: BarPosition.End, controller: this.tabsController }) {
      //Home
      TabContent() {
        Home()
      }
      .padding({
        left: $r('app.float.mainPage_padding'),
        right: $r('app.float.mainPage_padding')
      })
      .backgroundColor($r('app.color.mainPage_backgroundColor'))
      .tabBar(this.TabBuilder(CommonConstants.HOME_TITLE
        , CommonConstants.HOME_TAB_INDEX
        , $r('app.media.home_selected'), $r('app.media.home_normal')))

      //Settings
      TabContent(){
        Settings()
      }
      .padding({
        left: $r('app.float.mainPage_padding'),
        right: $r('app.float.mainPage_padding')
      })
      .backgroundColor($r('app.color.mainPage_backgroundColor'))
      .tabBar(this.TabBuilder(CommonConstants.MINE_TITLE
        , CommonConstants.MINE_TAB_INDEX
        , $r('app.media.mine_selected'), $r('app.media.mine_normal')))
    }
    .width(CommonConstants.FULL_PARENT)
    .backgroundColor(Color.White)
    .barHeight($r('app.float.mainPage_barHeight'))
    .barMode(BarMode.Fixed)//平均分配宽度
    .onChange((index: number) => {
      this.currentIndex = index;
    })
  }
}