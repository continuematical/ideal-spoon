import SettingData from '../common/bean/SettingData'
import CommonConstants from '../common/constants/CommonConstants'
import StyleConstants from '../common/constants/StyleConstants'
import HomeViewModel from '../viewmodel/HomeViewModel'

@Entry
@Component
struct Index {
  private settingArray: Array<SettingData> = HomeViewModel.settingArr

  onPageShow(){
    
  }

  @Builder settingItem() {
    List() {
      ForEach(this.settingArray.slice(CommonConstants.START_INDEX, CommonConstants.END_INDEX), (item, index) => {
        ListItem() {

        }
      })
    }
    .divider({
      strokeWidth: $r('app.float.setting_item_divider_width'),
      startMargin: $r('app.float.setting_item_divider_start_margin'),
      color: $r('app.color.setting_item_divider'),
      endMargin: StyleConstants.DIVIDER_END_MARGIN_PERCENT
    })
  }

  build() {
    Column() {

    }
  }
}

@Extend(Row) function blockBackground(marginTop: string) {
  .backgroundColor(Color.White)
  .borderRadius($r('app.float.block_background_radius'))
  .margin({
    top: marginTop
  })
  .width(StyleConstants.BLOCK_WIDTH_PERCENT)
  .padding({
    top: $r('app.float.block_vertical_padding'),
    bottom: $r('app.float.block_vertical_padding')
  })
}