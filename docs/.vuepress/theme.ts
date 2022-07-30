import { hopeTheme } from "vuepress-theme-hope";
import navbar from "./navbar";
import sidebar from "./sidebar";

export default hopeTheme({
  author: {
    name: "kitUIN",
    url: "https://github.com/kitUIN",
  },

  iconAssets: "iconfont",

  logo: "/logo.png",

  repo: "kitUIN/BikaClient",

  // navbar
  navbar: navbar,

  // sidebar
  sidebar: sidebar,

  footer: "Theme By <a href='https://github.com/vuepress-theme-hope/vuepress-theme-hope'>vuepress-theme-hope</a>",

  displayFooter: true,

  pageInfo: ["Author", "Original", "Date", "Category", "Tag", "ReadingTime"],



  plugins: {
    

    // 如果你不需要评论，可以直接删除 comment 配置，
    // 以下配置仅供体验，如果你需要评论，请自行配置并使用自己的环境，详见文档。
    // 为了避免打扰主题开发者以及消耗他的资源，请不要在你的正式环境中直接使用下列配置!!!!!
    comment: {
      

      /**
       * Using Twikoo
       */
      // provider: "Twikoo",
      // envId: "https://twikoo.ccknbc.vercel.app",

      /**
       * Using Waline
       */
      provider: "Waline",
      serverURL: "https://kituin-comments.vercel.app",
    },

    mdEnhance: {
      enableAll: true,
      presentation: {
        plugins: ["highlight", "math", "search", "notes", "zoom"],
      },
    },
  },
});
