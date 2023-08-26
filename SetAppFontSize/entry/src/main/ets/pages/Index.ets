import router from '@ohos.router'
import SettingData from '../common/bean/SettingData'
import CommonConstants from '../common/constants/CommonConstants'
import StyleConstants from '../common/constants/StyleConstants'
import Logger from '../common/util/Logger'
import SettingItemComponent from '../view/SettingItemComponent'
import TitleBarComponent from '../view/TitleBarComponent'
import HomeViewModel from '../viewmodel/HomeViewModel'

const TAG = '[Index]'

@Entry
@Component
struct Index {
  private settingArray: Array<SettingData> = HomeViewModel.initSettingData()
  @State changeFontSize: number = 0

  onPageShow() {

  }

  @Builder settingItem() {
    List() {
      ForEach(this.settingArray.slice(CommonConstants.START_INDEX, CommonConstants.END_INDEX), (item, index) => {
        ListItem() {
          SettingItemComponent({
            settingData: item,
            changeFontSize: this.changeFontSize,
            itemClick: () => {
              if (index === CommonConstants.SET_FONT_INDEX) {
                router.pushUrl({
                  url: CommonConstants.SET_URL
                }).catch((error) => {
                  Logger.error(TAG, 'Index push error ' + JSON.stringify(error))
                })
              }
            }
          })
        }
      }, item => item.settingName.id.toString())
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
      TitleBarComponent({
        isBack: false,
        title: $r('app.string.home_title')
      })
      Row() {
        SettingItemComponent({
          settingData: this.settingArray[CommonConstants.DISPLAY_INDEX],
          changeFontSize: this.changeFontSize,
          itemClick: () => {
          }
        })
      }
      .blockBackground(StyleConstants.BLOCK_TOP_MARGIN_FIRST_PERCENT)

      Row() {
        SettingItemComponent({
          settingData: this.settingArray[CommonConstants.VOICE_INDEX],
          changeFontSize: this.changeFontSize,
          itemClick: () => {
          }
        })
      }
      .blockBackground(StyleConstants.BLOCK_TOP_MARGIN_SECOND_PERCENT)

      Row() {
        this.settingItem()
      }
      .blockBackground(StyleConstants.BLOCK_TOP_MARGIN_SECOND_PERCENT)
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