export default class TaskItemBean {
  taskName: string
  updateDate: string
  progressValue: number

  constructor(taskName: string, updateDate: string, progressValue: number) {
    this.taskName = taskName
    this.updateDate = updateDate
    this.progressValue = progressValue;
  }
}