import { defineUserConfig } from "vuepress";
import theme from "./theme";

export default defineUserConfig({
  lang: "zh-CN",
  title: "主题演示",
  description: "BikaClient的文档",

  base: "/wiki/bikaclient/",

  theme,
});
