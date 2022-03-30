# simple_shell
## By Chiara, Declan and Matthew

.gitignore
- *~ (all emacs buffer files)
- local_* (all local testing files)

### REPO STANDARDS
**Commit Messages:**   
**usage:**   <type>: subject line in lower case.   
**example:** docs: update readme file   

**Allowed** <type> values: #
- **feat** for a new feature for the user, not a new feature for build script. Such commit will trigger a release bumping a MINOR version.
- **fix** for a bug fix for the user, not a fix to a build script. Such commit will trigger a release bumping a PATCH version.
- **perf** for performance improvements. Such commit will trigger a release bumping a PATCH version.
- **docs** for changes to the documentation.
- **style** for formatting changes, missing semicolons, etc.
- **refactor** for refactoring production code, e.g. renaming a variable.
- **test** for adding missing tests, refactoring tests; no production code change.
- **build** for updating build configuration, development tools or other changes irrelevant to the user.
   
**Branch Naming:**   
**Usage:**   shell_<tasknumber>   
**Example:** shell_0.1   

Day_1 Folder - contains all tasks done in day 1, and is kept to be used as a reference for all future work.