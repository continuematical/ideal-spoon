import ChatData from '../common/bean/ChatData'
import { ItemDirection } from '../common/bean/ItemDirection'
import CommonConstants from '../common/constants/CommonConstants'
import StyleConstants from '../common/constants/StyleConstants'
import ChatItemComponent from '../view/ChatItemComponent'
import TitleBarComponent from '../view/TitleBarComponent'
import SetViewModel from '../viewmodel/SetViewModel'

@Entry
@Component
export default struct SetFontSizePage {
  private chatArr: Array<ChatData> = SetViewModel.initChatData()
  @State changeFontSize: number = 0
  @State fontSizeText: Resource = $r('app.string.set_font_size')

  build() {
    Column() {
      TitleBarComponent({
        title: $r('app.string.set_title'),
        isBack: true
      })

      if (this.changeFontSize > 0) {
        List() {
          ForEach(this.chatArr, (item, index) => {
            ListItem() {
              ChatItemComponent({
                chatData: item,
                changeFontSize: this.changeFontSize,
              })
            }
          }, item => item.content.id.toString())
        }
      }

      SlideLayout({
        fontSizeText: $fontSizeText,
        changeFontSize: $changeFontSize,
      })
    }
    .backgroundColor($r('sys.color.ohos_id_color_sub_background'))
    .height(StyleConstants.FULL_HEIGHT)
    .width(StyleConstants.FULL_WIDTH)
  }
}

@Component
struct SlideLayout {
  @Link fontSizeText: Resource
  @Link changeFontSize: number

  build() {
    Column() {
      Text($r('app.string.set_font_size'))
        .fontSize($r('app.float.set_text'))
        .fontColor($r('app.color.text'))
        .margin({
          left: StyleConstants.SLIDER_LAYOUT_LEFT_PERCENT,
          top: StyleConstants.SLIDER_TOP_MARGIN_PERCENT
        })
        .fontWeight(FontWeight.Medium)

      Column() {
        Text(this.fontSizeText)
          .fontSize($r('app.float.set_text'))
          .fontColor($r('app.color.text'))

        Row() {
          Text($r('app.string.set_char_a'))
            .fontSize($r('app.float.set_small_a'))
            .fontWeight(FontWeight.Medium)
            .fontColor($r('app.color.text'))
            .width(StyleConstants.A_WIDTH_PERCENT)
            .padding({
              right: $r('app.float.a_right_padding')
            })
            .textAlign(TextAlign.End)

          Slider({
            value: this.changeFontSize === CommonConstants.SET_SIZE_HUGE
              ? CommonConstants.SET_SLIDER_MAX : this.changeFontSize,
            min: CommonConstants.SET_SLIDER_MIN,
            max: CommonConstants.SET_SLIDER_MAX,
            step: CommonConstants.SET_SLIDER_STEP,
            style: SliderStyle.InSet
          })
            .showSteps(true)
              //是否显示步数大小
            .width(StyleConstants.SLIDER_WIDTH_PERCENT)
            .onChange((value) => {
              this.changeFontSize = value
            })

          Text($r('app.string.set_char_a'))
            .fontSize($r('app.float.set_big_a'))
            .fontColor($r('app.color.text'))
            .width(StyleConstants.A_WIDTH_PERCENT)
            .padding({
              left: $r('app.float.a_left_padding')
            })
        }
      }
      .backgroundColor(Color.White)
      .borderRadius($r('app.float.block_background_radius'))
      .width(StyleConstants.BLOCK_WIDTH_PERCENT)
      .padding({
        top: $r('app.float.slider_top_padding'),
        bottom: $r('app.float.slider_bottom_padding')
      })
      .margin({
        left: StyleConstants.SLIDER_HORIZONTAL_MARGIN_PERCENT,
        right: StyleConstants.SLIDER_HORIZONTAL_MARGIN_PERCENT,
        top: StyleConstants.SLIDER_TOP_MARGIN_PERCENT,
        bottom: StyleConstants.SLIDER_BOTTOM_MARGIN_PERCENT,
      })
    }
    .alignItems(HorizontalAlign.Start)
    .justifyContent(FlexAlign.End)
  }
}