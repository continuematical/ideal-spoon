import DataModel from './DataModel'

//删除所选项
export function deleteSelected() {
  DataModel.deleteData(this.selectArray)
  this.targetData = DataModel.getData()
  this.overallProgressChanged = !this.overallProgressChanged
  this.isEditMode = false
}

//判断是否全部选择
export function isSelectedAll(): boolean {
  if (this.selectArray.length === 0) return false
  let deSelectCount = this.selectArray.filter(selected => selected === false).length;
  if (deSelectCount === 0) {
    this.selectAll = true
    return true
  }
  this.selectAll = false
  return false
}

//是否选择
export function isSelectRows(): boolean {
  return this.selectArray.filter(selected => selected === true).length !== 0
}

export function selectAllOrCancel(selectStatus: boolean) {
  let newSelectArray = []
  this.targetData.forEach(() => {
    newSelectArray.push(selectStatus)
  })
  this.selectArray = newSelectArray
}