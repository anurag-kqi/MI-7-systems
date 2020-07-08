FROM ubuntu:20.04
copy socm .
CMD /bin/bash -c "trap : TERM INT; sleep infinity & wait"
