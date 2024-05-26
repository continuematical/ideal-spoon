import { createApp } from 'vue'
import '@/style/reset.scss'
//引用根组件app
import App from '@/App.vue'
//引入全局组件
import HospitalTop from '@/components/hospital_top/index.vue'
//用来创建应用实例方法
const app=createApp(App)
app.mount('#app')
//声明全局组件
app.component('HospitaiTop', HospitalTop)