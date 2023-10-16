import TaskItemBean from '../common/bean/TaskItemBean'
import { CommonConstants } from '../common/constants/CommonConstants'
import getCurrentTime from '../common/util/DateUtil'
import TargetInformation from '../View/TargetInformation'
import TargetList from '../View/TargetList'
import DataModel from '../ViewModel/DataModel'
import AddTargetDialog from '../View/AddTargetDialog'
import { saveTask } from '../ViewModel/MainPageModel'

@Entry
@Component
struct Index {
  @State targetData: Array<TaskItemBean> = DataModel.getData()
  @State totalTasksNumber: number = 0
  @State completedTaskNumber: number = 0
  @State latestUpdateDate: string = CommonConstants.DEFAULT_PROGRESS_VALUE
  @Provide @Watch('onProgressChanged') overallProgressChanged: boolean = false

  build() {
    Column() {
      //this.titleBar()
      // TargetInformation({
      //   completeTaskNumber: this.completedTaskNumber,
      //   latestUpdateDate: this.latestUpdateDate,
      //   totalTaskNumber: this.totalTasksNumber
      // })

      // TargetList({
      //   targetData: $targetData,
      //   onAddClick: () => this.dialogController.open()
      // })
      //   .height(CommonConstants.LIST_BOARD_HEIGHT)
    }
    .width(CommonConstants.FULL_WIDTH)
    .height(CommonConstants.FULL_HEIGHT)
    .backgroundColor($r('app.color.index_background'))
  }

  dialogController: CustomDialogController = new CustomDialogController({
    builder: AddTargetDialog({
      onClickOk: saveTask.bind(this)
    }),
    alignment: DialogAlignment.Bottom,
    offset: {
      dx: CommonConstants.DIALOG_OFFSET_X,
      dy: $r('app.float.dialog_offset_y')
    },
    customStyle: true,
    autoCancel: false
  })

  onProgressChanged() {
    this.totalTasksNumber = this.targetData.length
    this.completedTaskNumber = this.targetData.filter((item) => {
      return item.progressValue === CommonConstants.SLIDER_MAX_VALUE
    }).length
    this.latestUpdateDate = getCurrentTime()
  }

  @Builder titleBar() {
    Text($r('app.string.title'))
      .width(CommonConstants.TITLE_WIDTH)
      .height($r('app.float.title_height'))
      .fontSize($r('app.float.title_font'))
      .fontWeight(CommonConstants.FONT_WEIGHT_LARGE)
      .textAlign(TextAlign.Start)
      .margin({
        top: $r('app.float.title_margin'),
        bottom: $r('app.float.title_margin')
      })
  }
}