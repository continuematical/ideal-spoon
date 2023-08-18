import TaskItemBean from '../common/bean/TaskItemBean'
import { CommonConstants } from '../common/constants/CommonConstants'
import { changeProgress } from '../ViewModel/TaskListItemModel'
import ProgressEditPanel from './ProgressEditPanel'

@Component
export default struct TargetListItem {
  private targetItem: TaskItemBean //数据类
  private index: number
  @State slideMode: number = CommonConstants.DEFAULT_SLIDER_MODE //默认滑动类型
  @State latestProgress: number = 0 //进度条更新
  @State updateDate: string = '' //日期
  @State isExpanded: boolean = false
  @Prop isEditMode: boolean
  //点击列表项的 index ，与父组件相连
  @Link @Watch('onClickIndexChange') clickIndex: number
  @Link selectedArr: Array<boolean>
  @Consume overallProgressChanged: boolean

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
      .alignItems(HorizontalAlign.End)
    }
    .width(CommonConstants.FULL_WIDTH)
  }

  aboutToAppear() {
    //初始化进度条，日期
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
        if (this.isExpanded) {
          Blank()
          ProgressEditPanel({
            slidingProgress: this.latestProgress,
            slideMode: $slideMode,
            onClickOK: changeProgress.bind(this),
            onCancel: () => this.isExpanded = false
          })
            .transition({
              scale: {
                x: CommonConstants.TRANSITION_ANIMATION_X,
                y: CommonConstants.TRANSITION_ANIMATION_Y
              }
            })
        }
      }
      .padding({
        left: $r('app.float.list_padding'),
        top: $r('app.float.list_padding_top'),
        bottom: $r('app.float.list_padding_right'),
        right: $r('app.float.list_padding_right')
      })
      .height(this.isExpanded ? $r('app.float.expanded_item_height') : $r('app.float.list_item_height'))
      .width(CommonConstants.FULL_WIDTH)
      .opacity(
          this.latestProgress === CommonConstants.SLIDER_MAX_VALUE ? CommonConstants.OPACITY : CommonConstants.NO_OPACITY
      )
      .borderRadius(CommonConstants.LIST_RADIUS)
      .animation({
        duration: CommonConstants.DURATION
      })
      .backgroundColor(this.selectedArr[this.index] ? $r('app.color.edit_blue') : Color.White)
      .onClick(() => {
        if (this.slideMode === CommonConstants.CLICK_SLIDER_MODE) {
          this.slideMode = CommonConstants.DEFAULT_SLIDER_MODE
          return
        }
        //点击按钮转变为编辑模式
        if (!this.isEditMode) {
          //如果不是编辑模式
          animateTo({
            duration: CommonConstants.DURATION
          }, () => {
            this.isExpanded = !this.isExpanded
          })
          this.clickIndex = this.index
        }
      })

      if (this.isEditMode) {
        Row() {
          Checkbox()
            .select(this.selectedArr[this.index])
            .selectedColor($r('app.color.main_blue'))
            .width(CommonConstants.CHECKBOX_WIDTH)
            .margin({
              right: $r('app.float.list_padding')
            })
            .onChange((isCheck: boolean) => {
              this.selectedArr[this.index] = isCheck
            })
        }
        .width(CommonConstants.FULL_WIDTH)
        .justifyContent(FlexAlign.End)
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