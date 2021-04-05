cat input | grep -xv "^[A-Za-z][-_\.\+A-Za-z0-9]*[@][-A-Za-z0-9]*[\.][A-Za-z]*" | grep -xv "^[A-Za-z][-_\.\+A-Za-z0-9]*[@][-A-Za-z0-9]*[\.][A-Za-z]*[\.][A-Za-z]*"
