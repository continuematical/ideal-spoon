import Layout from '@/layout'
import Router from 'vue-router'

//不需要判断权限的路由
export const constantRoutes = [
    {
        path: '/redirect',
        hidden: true,//不在侧边向显示
        children: [
            {

            }
        ]
    }
]

//需要动态判断权限
export const asyncRoutes = [
    {
        path: '/permission',
        component: Layout,
        redirect: '/permission/page',
        alwaysShow: true,
        name: 'Permission',
        meta: {
            title: 'Permission',
            icon: 'lock',
            roles: ['admin','editor']
        },
        children: [

        ]
    }
]


const createRouter = () => new Router({
    scrollBehavior: () => ({y: 0}),
    routes: constantRoutes
})

const router = createRouter()

export function resetRouter(){
    const newRouter = createRouter()
    router.matcher = newRouter.matcher
}

export default router