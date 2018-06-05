# Tree Sort

This is a simple tree-sort example I made some time ago on C++

This is meant to work on linux, you pipe in a newline separated list of numbers (via input stream) and the code will gladly sort it for you. I made it to be as efficient as possible (That's still coming from my old self, so beware).
After its done it will spit it out to the output stream so you can pipe it, store it or look at it go.

Example:
```bash
g++ tree-sort.cpp -o tree-sort
cat test_sample | ./tree-sort > test_sample.sort
```

LICENCE: This is completely free to use, modify, print, laugh at or insult. I give it "as is" and I do not give guarantees other than "It worked on my computer". Feel free to include it in your school project, change the variable names and hope the professor doesn't find out.