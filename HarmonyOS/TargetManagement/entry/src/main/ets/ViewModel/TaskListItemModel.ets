import getCurrentTime from '../common/util/DateUtil'
import DataModel from './DataModel'

export function changeProgress(progress: number) {
  this.latestProgress = progress
  this.updateDate = getCurrentTime()
  let result = DataModel.updateProgressValue(this.index, this.latestProgress, this.updateUpdate)
  if (result) this.overallProgressChanged = !this.overallProgressChanged
  this.isExpanded = false
}