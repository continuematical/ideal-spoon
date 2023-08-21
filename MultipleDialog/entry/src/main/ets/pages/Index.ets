import CommonConstants from '../common/contants/CommonConstants'
import CommonUtils from '../common/Utils/CommonUtils'

@Entry
@Component
struct Index {
  build() {
    Column() {
      Image($r('app.media.ic_back'))
        .width($r('app.float.image_back_size'))
        .height($r('app.float.image_back_size'))
        .alignSelf(ItemAlign.Start)
        .margin({
          top: CommonConstants.BACK_MARGIN_TOP,
          left: CommonConstants.BACK_MARGIN_LEFT
        })
        .onClick(() => {
          CommonUtils.alertDialog()
        })

      Image($r('app.media.ic_avatar'))
        .width($r('app.float.avatar_size'))
        .height($r('app.float.avatar_size'))
        .alignSelf(ItemAlign.Center)
        .margin({
          top: CommonConstants.AVATAR_MARGIN_TOP
        })

      Text($r('app.string.text_personal_title'))
        .fontColor(Color.Black)
        .fontSize($r('app.float.personal_font_size'))
        .margin({
          top: CommonConstants.PERSONAL_MARGIN_TOP
        })
        .align(Alignment.Center)
    }
    .width(CommonConstants.FILL_WIDTH)
    .height(CommonConstants.FULL_HEIGHT)
    .backgroundColor($r('app.color.column_background_color'))
  }
}