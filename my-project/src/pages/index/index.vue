<template>
	<view>
		<view class="main-page">
			<view class="page-section page-section-gap">
				<map style="width: 100%; height: 100vh;" 
                :latitude="latitude" 
                :longitude="longitude" 
                :markers="markers"
                @tap="clickMap">
				</map>
			</view>

            <cover-view class="search_result">
                <uni-search-bar
                    placeholder="请输入你想去哪"
                    bgColor="#EEEEEE"
                    @confirm="search"
                />
            </cover-view>
		</view>
	</view>
</template>

  

<script>

import amap from '../../../lib/amap-wx.130.js';  
var that;
var amapPlugin = new amap.AMapWX({
	key: 'a5030a967956358401f1c4c8ed09128d',//高德地图key
})
export default {
	data() {
		return {
            map:null,
			poisdatas: [],
			longitude:0,
            latitude:0,
            name:'',
            address:'',
            markers:[]
		}
	},

	onLoad() {
		that = this
        that.handleAuthorize()
        //that.getAround()
        that.initMarkers()
	},

	methods: {

        //用户授权
        handleAuthorize(){
            uni.authorize({
                scope: 'scope.userLocation',
                success: (result) => {
                    that.getLocationFn()
                },
                //授权失败
                fail: (error) => {
                    err = err['errMsg']
                    uni.showModal({
                        title: '温馨提示',
                        content: '为享受智能小程序，您必须授权!',
                        showCancel: false,
                        confirmText: '确认授权'
                    })
                     // 这里只设置了确认按钮，没有取消按钮
                    .then(res => {
                        //res ： [null, {cancel: false, confirm: true, errMsg: 'showModal: ok'}]
                        if(res[1]['confirm']) { // 点击了确认按钮时
                            // 调用下边方法时，会弹出 【使用我的地理位置】界面， 未设置直接返回，还是会走fail授权失败的函数，
                            // 还是会弹出上边的温馨提示！！！
                            // 如果设置, scope.userLocation: true
                            uni.openSetting({
                                success(res) {
                                // 如果不设置，res结果：
                                // {errMsg: "openSetting:ok", authSetting: {scope.userLocation: false}}
                                // 如果设置, res结果： 
                                // {errMsg: "openSetting:ok", authSetting: {scope.userLocation: true}}
                                // console.log('小程序设置界面：', res)
                                }
                            })
                        }
                    })
                }
            })
        },

        //获取经纬度
        getLocationFn() {
            uni.getLocation({
                type: 'gcj02', // <map> 组件默认为国测局坐标gcj02
                altitude: true,
                success(res) {
                    console.log('返回的位置信息', res)
                    that.latitude=res.latitude
                    that.longitude=res.longitude

                    that.getAddress(res.latitude+','+res.longitude)
                }
            })
        },

        /**
         * 解析地址
         * 根据经纬度解析出地址名字
         */
        getAddress(loc){
            if(loc!=null && loc!=''){
                amapPlugin.getRegeo({
                    iconPath:'http://img.wisdomtaxi.com/amap_icon.png',
                    width:'37.5rpx',
                    height:'37.5rpx',
                    location:loc,
                    success:function(res){
                        that.name=res[0].name
                        that.address=res[0].address
                        
                        console.log('完整位置信息',res)
                    },
                    fail:function(info){
                        console.log(info)
                    }
                })
            }
        },

        //初始化地图标点
        initMarkers(){
            var markers_new=[]

            //武汉大学
            markers_new.push({
                id:1,
                width:20,
                height:20,
                iconPath:'/static/around_location.png',
                latitude:30.53926,
                longitude:114.35537,
                address:'武汉大学',
                name:'武汉大学',
                callout:{
                    padding: 10, //callout 文本边缘留白
                    fontSize: 15, //callout  文字大小
                    gColor: 'white', //callout 背景颜色
                    color: '#6B8E23', //callout 文字颜色
                    borderRadius: 5, //边框圆角
                    display: 'ALWAYS', //callout 'BYCLICK':点击显示; 'ALWAYS':常显
                    content: '武汉大学珞珈山' //地理位置名称
                }
            })

            //宝通寺
            markers_new.push({
                id:2,
                width:20,
                height:20,
                iconPath:'/static/around_location.png',
                latitude:30.53219,
                longitude:114.34086,
                address:'宝通寺',
                name:'宝通寺',
                callout:{
                    padding: 10, //callout 文本边缘留白
                    fontSize: 15, //callout  文字大小
                    gColor: 'white', //callout 背景颜色
                    color: '#6B8E23', //callout 文字颜色
                    borderRadius: 5, //边框圆角
                    display: 'ALWAYS', //callout 'BYCLICK':点击显示; 'ALWAYS':常显
                    content: '宝通寺' //地理位置名称
                }
            })

            that.markers=markers_new

            console.log('初始化地图标点成功')
        },

        //获取周边信息
        getAround(){
            amapPlugin.getPoiAround({
                iconPathSelected: "../../static/location_selected.png", 
                iconPath: '../../static/location.png', //如：..­/..­/img/marker.png
                success: function(data) {
                    //成功回调
                    console.log('位置回调',data)
                    that.markers = data.markers;
                    that.poisdatas = data.poisData;
                    var markers_new = [];
                    that.markers.forEach(function(item, index) {
                        markers_new.push({
                            id: item.id, //marker 序号
                            width: item.width, //marker 宽度
                            height: item.height, //marker 高度
                            //必须为绝对路径，不能是相对路径
                            iconPath: '/static/location.png', //marker 图标路径
                            latitude: item.latitude, //marker  纬度
                            longitude: item.longitude, //marker 经度
                            address: item.address,//marker 地址
                            name: item.name,//marker 名字
                            //自定义标记点上方的气泡窗口
                            joinCluster:true,
                            callout: {
                                padding: 10, //callout 文本边缘留白
                                fontSize: 15, //callout  文字大小
                                bgColor: 'white', //callout 背景颜色
                                color: '#6B8E23', //callout 文字颜色
                                borderRadius: 5, //边框圆角
                                display: 'ALWAYS', //callout 'BYCLICK':点击显示; 'ALWAYS':常显
                                content: that.poisdatas[index].name //地理位置名称
                            }
                        })
                    })
                    that.markers = markers_new;
                },
                fail: function(info) {
                    //失败回调
                    console.log("info", info)
                }
		    })
        },

		//点击地图时触发
		clickMap(info){
            console.log("点击地图")
            uni.chooseLocation({
                success:(success)=>{
                    that.longitude=success.longitude;
                    that.latitude=success.latitude;
                    //为标记点经纬度重新赋值【在data中赋坐标的方式无效】
                    that.covers[0].longitude=success.longitude;
                    that.covers[0].latitude=success.latitude;
                    // console.log('位置名称：' + res.name);
                    // console.log('详细地址：' + res.address);
                    // console.log('纬度：' + res.latitude);
                },
                
                fail:(fail)=>{
                    uni.showToast({
                        title: '获取位置失败',
                        icon: 'success',
                        mask: true
                    })
                },
            })
        },

        //搜索框
        search(){

        }
	}
}
</script>

<style scoped>
    .search_result{
        padding-top: 10px;
		padding-bottom: 20px;
		text-align: center;
    }
</style>