import CommonConstants from '../common/constants/CommonConstants'
import { FileManager } from './FileManager'

@Entry
@Component
struct Index {
  @State currentPageIndex: number = CommonConstants.INDEX_DEFAULT_SELECT

  @Builder TabBuilder(item, index) {
    Column() {
      Image(this.currentPageIndex === index ? item.selectedIcon : item.defaultIcon)
        .width($r('app.float.index_tab_icon_size'))
        .height($r('app.float.index_tab_icon_size'))
        .objectFit(ImageFit.Contain)

      Text(item.content)
        .fontColor(this.currentPageIndex === index ? $r('app.color.index_tab_font_color') : Color.Black)
        .fontSize($r('app.float.index_tab_font_size'))
        .margin({
          top: $r('app.float.index_tab_vertical_margin')
        })
        .opacity(this.currentPageIndex === index
          ? $r('app.float.index_tab_font_selected_opacity')
          : $r('app.float.index_tab_font_default_opacity'))
    }
    .justifyContent(FlexAlign.Center)
    .width(CommonConstants.FULL_LENGTH)
    .height(CommonConstants.FULL_LENGTH)
  }

  build() {
    Tabs({
      barPosition: BarPosition.End,
      index: this.currentPageIndex
    }) {
      ForEach(CommonConstants.INDEX_TAB, (item, index) => {
        TabContent() {
          if (index === CommonConstants.INDEX_DEFAULT_SELECT) {
            FileManager()
          }
        }
        .tabBar(this.TabBuilder(item, index))
      }, item => JSON.stringify(item))
    }
    .width(CommonConstants.FULL_LENGTH)
    .height(CommonConstants.FULL_LENGTH)
    .barMode(BarMode.Fixed)
    .onChange((index) => {
      this.currentPageIndex = index
    })
  }
}