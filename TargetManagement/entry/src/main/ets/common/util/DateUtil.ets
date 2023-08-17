import { CommonConstants } from '../constants/CommonConstants'

export default function getCurrentTime(): string {
  let date = new Date()
  let year = date.getFullYear()
  let month = date.getMonth() + CommonConstants.PLUS_ONE
  let day = date.getDate()
  let hours = date.getHours()
  let minutes = date.getMinutes().toString()
  let second = date.getSeconds().toString()


  if (parseInt(minutes) < CommonConstants.TEN)
    minutes = '0${minutes}'
  if (parseInt(second) < CommonConstants.TEN)
    second = '0${second}'
  return '${year}/${month}/${day} ${hours}:${minutes}:${second}'
}