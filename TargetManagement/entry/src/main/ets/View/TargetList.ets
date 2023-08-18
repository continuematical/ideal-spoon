import TaskItemBean from '../common/bean/TaskItemBean'
import { CommonConstants } from '../common/constants/CommonConstants'
import { isSelectedAll, selectAllOrCancel } from '../ViewModel/TaskListViewModel'
import TargetListItem from './TargetListItem'

@Component
export default struct TargetList {
  //项目列表
  @Link targetData: Array<TaskItemBean>
  //是否为编辑模式
  @State isEditMode: boolean = false
  //选择的列表项
  @State selectArray: Array<boolean> = []
  //是否全部选择
  @State selectAll: boolean = false
  //是否改变进度条
  @Consume overallProgressChanged: boolean
  //当前点击按钮
  @State clickIndex: number = CommonConstants.DEFAULT_CLICK_INDEX
  onAddClick: () => void

  build() {
    Column() {
      Row() {
        Text($r('app.string.sub_goals'))
          .fontSize($r('app.float.secondary_title'))
          .fontWeight(CommonConstants.FONT_WEIGHT_LARGE)
          .fontColor($r('app.color.title_black_color'))

        Blank()

        if (this.targetData.length > 0) {
          if (this.isEditMode) {
            Text($r('app.string.cancel_button'))
              .operateTextStyle($r('app.color.main_blue'))
              .margin({
                left: $r('app.float.operate_button_margin')
              })
              .onClick(() => {
                this.selectAll = false
                this.isEditMode = false
                selectAllOrCancel.call(this, false)
              })

            Text($r('app.string.select_all_button'))
              .operateTextStyle($r('app.color.main_blue'))
              .margin({
                left: $r('app.float.operate_button_margin')
              })

            Checkbox()
              .select(isSelectedAll.call(this))

          } else {
            Text($r('app.string.edit_button'))
              .operateTextStyle($r('app.color.main_blue'))
              .onClick(() => {
                this.isEditMode = true
                selectAllOrCancel.call(this, false)
              })
          }
        }
      }

      List({
        space: CommonConstants.LIST_SPACE
      }) {
        ForEach(this.targetData, (item: TaskItemBean, index: number) => {
          ListItem() {
            TargetListItem({
              clickIndex: $clickIndex,
              selectedArr: $selectArray,
              isEditMode: this.isEditMode,
              index: index,
            })
          }
        }, (item, index) => JSON.stringify(item) + index)
      }

      Blank()
    }
    .width(CommonConstants.MAIN_BOARD_WIDTH)
    .height(CommonConstants.FULL_HEIGHT)
    .padding({
      top: $r('app.float.operate_row_margin')
    })
  }
}

@Extend(Button) function operateButtonStyle(color: Resource) {
  .width($r('app.float.button_width'))
  .height($r('app.float.button_height'))
  .fontSize($r('app.float.button_font'))
  .fontWeight(CommonConstants.FONT_WEIGHT)
  .fontColor(color)
  .backgroundColor($r('app.color.button_background'))
}

@Extend(Text) function operateTextStyle(color: Resource) {
  .fontSize($r('app.float.text_button_font'))
  .fontColor(color)
  .lineHeight($r('app.float.text_line_height'))
  .fontWeight(CommonConstants.FONT_WEIGHT)
}