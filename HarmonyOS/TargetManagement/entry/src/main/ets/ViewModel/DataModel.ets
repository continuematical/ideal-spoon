import TaskItemBean from '../common/bean/TaskItemBean'
import { CommonConstants } from '../common/constants/CommonConstants'
import Logger from '../common/util/Logger'

const TAG = '[DataModel]'

export class DataModel {
  private targetData: Array<TaskItemBean> = []

  getData(): Array<TaskItemBean> {
    return this.targetData
  }

  deleteData(selectArr: Array<boolean>) {
    if (!selectArr) Logger.error(TAG, 'Failed to delete data because selectArr is ' + selectArr)
    let dataLen = this.targetData.length - CommonConstants.ONE_TASK
    for (let index = 0; index < dataLen; index++) {
      if (selectArr[index]) this.targetData.splice(index, CommonConstants.ONE_TASK)
    }
  }

  addData(data: TaskItemBean) {
    if (!data) {
      Logger.error(data, 'addData error because data is: ' + data)
      return
    }
    this.targetData.push(data)
  }

  getLatestProgressValue(): number {
    if (!this.targetData.length) return 0;
    return this.targetData[this.targetData.length-CommonConstants.ONE_TASK].progressValue
  }

  updateProgressValue(index: number, updateValue: number, updateDate: string): boolean {
    if (!this.targetData[index]) return false
    this.targetData[index].progressValue = updateValue
    this.targetData[index].updateDate = updateDate
    return true
  }
}

export default new DataModel()