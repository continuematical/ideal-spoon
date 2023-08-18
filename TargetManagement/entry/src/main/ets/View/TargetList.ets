import TaskItemBean from '../common/bean/TaskItemBean'
import { CommonConstants } from '../common/constants/CommonConstants'
import TargetListItem from './TargetListItem'

@Component
export default struct TargetList {
  //项目列表
  @Link targetData: Array<TaskItemBean>
  @State isEditMode: boolean = false
  //选择的列表项
  @State selectArray: Array<boolean> = []
  @Consume overallProgressChanged: boolean
  @State clickIndex: number = CommonConstants.DEFAULT_CLICK_INDEX

  build() {
    Column() {
      Row()

      Blank()

      List({
        space: CommonConstants.LIST_SPACE
      }) {
        ForEach(this.targetData, (item: TaskItemBean, index: number) => {
          ListItem(){
            TargetListItem({

            })
          }
        })
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