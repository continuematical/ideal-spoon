import router from '@ohos.router'
import StyleConstants from '../common/constants/StyleConstants'

@Component
export default struct TitleBarComponent {
  private isBack: boolean
  private title: Resource

  build() {
    Row() {
      if (this.isBack) {
        Image($r('app.media.ic_public_back'))
          .height($r('app.float.title_ic_size'))
          .width($r('app.float.title_ic_size'))
          .margin({
            right: $r('app.float.title_ic_margin')
          })
          .onClick(() => {
            router.back()
          })
      }

      Text(this.title)
        .fontColor(Color.Black)
        .fontSize($r('sys.float.ohos_id_text_size_headline8'))
        .margin({
          left: $r('app.float.title_text_margin_left')
        })
        .fontWeight(FontWeight.Medium)
    }
    .width(StyleConstants.FULL_WIDTH)
    .height(StyleConstants.TITLE_BAR_HEIGHT_PERCENT)
    .padding({
      left: $r('app.float.title_padding_left')
    })
  }
}