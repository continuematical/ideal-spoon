import SettingData from '../common/bean/SettingData'
import StyleConstants from '../common/constants/StyleConstants'

@Component
export default struct SettingItemComponent {
  itemClick: () => void
  settingData: SettingData
  @Prop changeFontSize: number

  build() {
    Row() {
      Image(this.settingData.settingImage)
        .height($r('app.float.setting_item_ic_size'))
        .width($r('app.float.setting_item_ic_size'))
        .margin({
          left: $r('app.float.setting_ic_margin_left'),
          right: $r('app.float.setting_ic_margin_right')
        })

      Text(this.settingData.settingName)
        .fontSize(this.changeFontSize + StyleConstants.UNIT_FP)
        .fontColor($r('app.color.text'))
        .fontWeight(FontWeight.Medium)
    }
    .width(StyleConstants.FULL_WIDTH)
    .height($r('app.float.setting_item_height'))
    .onClick(() => {
      this.itemClick
    })
  }
}