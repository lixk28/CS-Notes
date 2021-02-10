1. [master与origin/master](#master与originmaster)


由于时间原因，只学习了一些git基础，而git分支，原理等一些内容没有学习，容易出现错误，因此在这里记录一些在使用git和github中遇到的问题。

# master与origin/master

master是本地分支，origin/master是服务端分支，当进行一次提交后，我们立刻将其push到origin/master，就可以在github上看到我们更新的结果。

但是，如果我们想要修改这次提交，是不能用`git commit --amend`，因为我们会修改一个已经被push了的commit，而产生了一个自己的版本。

```
---master---origin/master
    \
    your new version master
```

如果使用`git commit --amend`修改一个不存在的提交（即提交已经被push），再push的话，会产生下面的错误报告：
```
On branch master
Your branch and 'origin/master' have diverged,
and have 1 and 1 different commit each, respectively.
  (use "git pull" to merge the remote branch into yours)
nothing to commit, working directory clean
```
注意，`git commit --amend`只能用于修改本地未被push的提交。

解决的办法是：
```
git push -f
```

注意到，这种方法在团队协作中是十分危险的行为，但如果你的仓库只是你自己个人使用，那么就无关紧要了。

---