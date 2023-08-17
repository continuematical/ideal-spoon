//进度条
import { CommonConstants } from '../common/constants/CommonConstants'

@Component
export default struct ProgressEditPanel {
  @Link slideMode: number
  @Prop slidingProgress: number
  onCancel: () => void
  onClickOK: (progress: number) => void

  build() {
    Column() {
      Row() {
        Slider({
          style: SliderStyle.InSet,
          value: this.slidingProgress,
          min: CommonConstants.SLIDER_MIN_VALUE,
          max: CommonConstants.SLIDER_MAX_VALUE,
          step: CommonConstants.SLIDER_STEP
        })
          .width(CommonConstants.SLIDER_INNER_WIDTH)
          .onChange((value: number, mode: SliderChangeMode) => {
            this.slideMode = mode
            this.slidingProgress = Math.floor(value)
          })

        Text('${this.slidingProgress}')
          .fontSize($r('app.float.progress_font'))
          .fontWeight(CommonConstants.FONT_WEIGHT)
          .fontColor($r('app.color.dialog_progress'))
          .textAlign(TextAlign.Center)
          .margin({
            left: $r('app.float.slider_margin_left')
          })
      }
      .width(CommonConstants.SLIDER_WIDTH)
      .height(CommonConstants.SLIDER_HEIGHT)

      Row() {
        CustomButton({
          buttonText: $r('app.string.cancel_button')
        })
          .onClick(() => this.onCancel())
        CustomButton({
          buttonText: $r('app.string.confirm_button')
        })
          .onClick(() => this.onClickOK(this.slidingProgress))
      }
      .margin({
        top: CommonConstants.SLIDER_BUTTON_MARGIN
      })
      .width(CommonConstants.FULL_WIDTH)
      .justifyContent(FlexAlign.SpaceBetween)
    }
  }
}

@Component
struct CustomButton {
  @State buttonColor: Resource = $r('app.color.start_window_background')
  buttonText: Resource

  build() {
    Text(this.buttonText)
      .dialogButtonStyle()
      .backgroundColor(this.buttonColor)
      .borderRadius(CommonConstants.LIST_RADIUS)
      .textAlign(TextAlign.Center)
      .onTouch((event: TouchEvent) => {
        if (event.type === TouchType.Down) this.buttonColor = $r('app.color.custom_button_color')
        if (event.type === TouchType.Up) this.buttonColor = $r('app.color.start_window_background')
      })
  }
}

@Extend(Text) function dialogButtonStyle() {
  .fontSize($r('app.float.button_font'))
  .height($r('app.float.dialog_btn_height'))
  .width($r('app.float.dialog_btn_width'))
  .fontColor($r('app.color.main_blue'))
}