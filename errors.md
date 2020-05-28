# 常见错误

* int 溢出
* 题意读错（要先在例子上验证）

在 console 里执行，以防止翻译 MathJax
```JavaScript
for (const jax of MathJax.Hub.getAllJax()) {jax.SourceElement().previousSibling.classList.add('notranslate')}
```
