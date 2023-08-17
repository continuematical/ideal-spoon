import TaskItemBean from '../common/bean/TaskItemBean'
import { CommonConstants } from '../common/constants/CommonConstants'

@Component
export default struct TargetListItem {
  private targetItem: TaskItemBean //数据类
  private index: number
  @State slideMode: number = CommonConstants.DEFAULT_SLIDER_MODE //默认滑动类型
  @State latestProgress: number = 0 //进度条更新
  @State updateDate: string = '' //日期
  @State isExpanded: boolean = false
  @Link @Watch('onClickIndexChange') clickIndex: number;

  @Builder getTargetItemView() {
    Row() {
      Text(this.targetItem.taskName)
        .fontSize($r('app.float.list_font'))
        .fontWeight(CommonConstants.FONT_WEIGHT)
        .fontColor($r('app.color.title_black_color'))
        .width(CommonConstants.TASK_NAME_WIDTH)
        .textAlign(TextAlign.Start)
        .maxLines(CommonConstants.MAX_LINES)

      Blank()

      Column() {
        Text('${this.latestProgress}')
          .fontSize($r('app.float.list_font'))
          .fontWeight(CommonConstants.FONT_WEIGHT)
          .fontColor($r('app.color.title_black_color'))
        Row() {
          Text($r('app.string.latest_updateTime'))
            .opacityTextStyle()
          Text($r(this.updateDate))
            .opacityTextStyle()
        }
        .margin({
          top: $r('app.float.text_margin')
        })
      }
      .alignItems(HorizontalAlign.End
    }
    .width(CommonConstants.FULL_WIDTH)
  }

  aboutToAppear() {
    this.latestProgress = this.targetItem.progressValue
    this.updateDate = this.targetItem.updateDate
  }

  onClickIndexChange() {
    if (this.clickIndex != this.index) this.isExpanded = false
  }

  build() {
    Stack({
      alignContent: Alignment.Start
    }) {
      Column() {
        this.getTargetItemView()
        if (this.isExpanded){
          Blank()
          
        }
      }
    }
    .width(CommonConstants.FULL_WIDTH)
  }
}

//灰色字体
@Extend(Text) function opacityTextStyle() {
  .fontColor($r('app.color.title_black_color'))
  .fontSize($r('app.float.text_font'))
  .opacity(CommonConstants.OPACITY)
  .fontWeight(CommonConstants.FONT_WEIGHT)
}