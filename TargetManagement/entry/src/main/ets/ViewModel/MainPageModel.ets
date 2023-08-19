import promptAction from '@ohos.promptAction'
import TaskItemBean from '../common/bean/TaskItemBean'
import { CommonConstants } from '../common/constants/CommonConstants'
import getCurrentTime from '../common/util/DateUtil'
import DataModel from './DataModel'

export function saveTask(taskName: string) {
  if (taskName === '') {
    promptAction.showToast({
      message: $r('app.string.cannot_input_empty'),
      duration: CommonConstants.TOAST_TIME,
      bottom: CommonConstants.TOAST_MARGIN_BOTTOM
    })
    return
  }
  DataModel.addData(new TaskItemBean(taskName, getCurrentTime(), 0))
  this.targetData = DataModel.getData()
  this.overallProgressChanged = !this.overallProgressChanged
  this.dialogController.close()
}