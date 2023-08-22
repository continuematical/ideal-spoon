import CommonConstants from '../common/constants/CommonConstants'
import mainViewModel from '../ViewModel/MainViewModel'
import ItemData from '../common/beans/ItemData'

@Component
export default struct Home {
  private swiperController: SwiperController = new SwiperController();

  build() {
    Scroll() {
      Column({ space: CommonConstants.COMMON_SPACE }) {

        Column() {
          Text($r('app.string.mainPage_tabTitles_home'))
            .fontSize($r('app.float.page_title_text_size'))
            .fontWeight(FontWeight.Medium)
            .margin({
              top: $r('app.float.mainPage_tabTitles_margin')
            })
            .padding({
              left: $r('app.float.mainPage_tabTitles_padding')
            })
        }
        .width(CommonConstants.FULL_PARENT)
        .alignItems(HorizontalAlign.Start)

        Swiper(this.swiperController) {
          ForEach(mainViewModel.getSwiperImages(), (img: Resource) => {
            Image(img).borderRadius($r('app.float.home_swiper_borderRadius'))
          }, img => img.id)
        }
        .margin({ top: $r('app.float.home_swiper_margin') })
        .autoPlay(true) //是否自动播放

        Grid() {
          ForEach(mainViewModel.getFirstGridData(), (item: ItemData) => {
            GridItem() {
              Column() {
                Image(item.img)
                  .width($r('app.float.home_homeCell_size'))
                  .height($r('app.float.home_homeCell_size'))
                Text(item.title)
                  .fontSize($r('app.float.little_text_size'))
                  .margin({
                    top: $r('app.float.little_text_size')
                  })
              }
            }
          }, item => JSON.stringify(item))
        }
        .columnsTemplate('1fr 1fr 1fr 1fr')//设置当前网格布局列的数量
        .rowsTemplate('1fr 1fr')
        .columnsGap($r('app.float.home_grid_columnsGap'))//列与列的行距
        .rowsGap($r('app.float.home_grid_rowGap'))
        .padding({
          top: $r('app.float.home_grid_padding'),
          bottom: $r('app.float.home_grid_padding')
        })
        .height($r('app.float.home_grid_height'))
        .backgroundColor(Color.White)
        .borderRadius($r('app.float.home_grid_borderRadius'))


        Text($r('app.string.home_list'))
          .fontSize($r('app.float.normal_text_size'))
          .fontWeight(FontWeight.Medium)
          .width(CommonConstants.FULL_PARENT)
          .margin({
            top: $r('app.float.home_text_margin'),
            left:$r('app.float.home_text_margin')
          })

        Grid() {
          ForEach(mainViewModel.getSecondGridData(), (item: ItemData) => {
            GridItem() {
              Column() {
                Text(item.title)
                  .fontSize($r('app.float.normal_text_size'))
                  .fontWeight(FontWeight.Medium)
                Text(item.others)
                  .fontSize($r('app.float.home_list_margin'))
                  .fontColor($r('app.color.home_grid_fontColor'))
                  .margin({ top: $r('app.float.home_list_margin') })
              }
              .alignItems(HorizontalAlign.Start)
            }
            .padding({
              top: $r('app.float.home_list_padding'),
              left: $r('app.float.home_list_padding')
            })
            .borderRadius($r('app.float.home_backgroundImage_borderRadius'))
            .align(Alignment.TopStart)
            .backgroundImage(item.img)
            .backgroundImageSize(ImageSize.Cover)
            .width(CommonConstants.FULL_PARENT)
            .height(CommonConstants.FULL_PARENT)
          }, item => JSON.stringify(item))
        }
        .width(CommonConstants.FULL_PARENT)
        .height($r('app.float.home_secondGrid_height'))
        .columnsTemplate('1fr 1fr')
        .rowsTemplate('1fr 1fr')
        .columnsGap($r('app.float.home_grid_columnsGap'))
        .rowsGap($r('app.float.home_grid_rowGap'))
        .margin({
          bottom: $r('app.float.setting_button_bottom')
        })
      }
    }
    .height(CommonConstants.FULL_PARENT)
  }
}