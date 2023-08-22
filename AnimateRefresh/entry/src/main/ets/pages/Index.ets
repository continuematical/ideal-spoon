import CommonConstants from '../common/constants/CommonConstants'

@Entry
@Component
struct Index {
  @State currentPageIndex: number = CommonConstants.INDEX_DEFAULT_SELECT

  @Builder TabBuilder(item, index) {
    Column() {

    }
  }

  build() {
    Tabs({
      barPosition: BarPosition.End,
      index: this.currentPageIndex
    }) {
      ForEach(CommonConstants.INDEX_TAB, (item, index) => {
        TabContent()
          .tabBar(this.TabBuilder(item, index))
      }, item => JSON.stringify(item))
    }
  }
}