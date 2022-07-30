import { defineUserConfig } from "vuepress";
import theme from "./theme";

export default defineUserConfig({
  lang: "zh-CN",
  title: "BikaClient",
  description: "BikaClient的文档",

  base: "/",

  theme,
});
