import { CommonConstants } from '../common/constants/CommonConstants'

@Component
export default struct TargetInformation {
  @Prop latestUpdateDate: string
  @Prop totalTaskNumber: number
  @Prop completeTaskNumber: number

  build() {
    Column() {
      this.TargetItem()
      this.overallProgress()
    }
    .padding($r('app.float.target_padding'))
    .width(CommonConstants.MAIN_BOARD_WIDTH)
    .height($r('app.float.target_info_height'))
    .backgroundColor(Color.White)
    .borderRadius(CommonConstants.TARGET_BORDER_RADIUS)
  }

  @Builder TargetItem() {
    Row() {
      Image($r('app.media.ic_main'))
        .width($r('app.float.target_image_length'))
        .height($r('app.float.target_image_length'))
        .objectFit(ImageFit.Fill)
        .borderRadius(CommonConstants.IMAGE_BORDER_RADIUS)

      Column() {
        Text($r('app.string.target_name'))
          .fontSize($r('app.float.target_name_font'))
          .fontWeight(CommonConstants.FONT_WEIGHT)
          .width(CommonConstants.TITLE_WIDTH)

        Text($r('app.string.target_info'))
          .opacityTextStyle()
          .fontSize($r('app.float.target_name_font'))
          .margin({
            top: $r('app.float.title_margin')
          })
      }
      .margin({
        left: CommonConstants.TARGET_MARGIN_LEFT
      })
      .alignItems(HorizontalAlign.Start)
    }
    .width(CommonConstants.FULL_WIDTH)
  }

  @Builder overallProgress() {
    Row() {
      Column() {
        Text($r('app.string.overall_progress'))
          .fontSize($r('app.float.button_font'))
          .fontColor($r('app.color.title_black_color'))
          .fontWeight(CommonConstants.FONT_WEIGHT)

        Row() {
          Text($r('app.string.latest_updateTime'))
            .opacityTextStyle()

          Text(this.latestUpdateDate)
            .opacityTextStyle()
        }
      }
      .alignItems(HorizontalAlign.Start)

      Blank()

      Stack() {
        Row() {
          Text(this.completeTaskNumber.toString())
            .fontSize($r('app.float.progress_font'))
            .fontColor($r('app.color.main_blue'))
            .fontWeight(CommonConstants.FONT_WEIGHT)

          Text(`/${this.totalTaskNumber}`)
            .fontSize($r('app.float.progress_font'))
            .fontWeight(CommonConstants.FONT_WEIGHT)
        }

        Progress({
          value: this.completeTaskNumber,
          total: this.totalTaskNumber,
          type: ProgressType.Ring
        })
          .color($r('app.color.main_blue'))
          .style({
            strokeWidth: CommonConstants.STROKE_WIDTH
          })
          .width($r('app.float.progress_length'))
          .height($r('app.float.progress_length'))
      }
    }
    .width(CommonConstants.FULL_WIDTH)
    .height($r('app.float.progress_length'))
    .margin({
      top: $r('app.float.progress_margin_top')
    })
  }
}

@Extend(Text) function opacityTextStyle() {
  .fontSize($r('app.float.text_font'))
  .fontColor($r('app.color.title_black_color'))
  .opacity(CommonConstants.OPACITY)
  .fontWeight(CommonConstants.FONT_WEIGHT)
}