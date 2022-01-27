build:
	make -f ff2mathtest.mk
	make -f iff2mathtest.mk
	make -f ff2mathop.mk
	make -f iff2mathop.mk

mk:
	# https://github.com/johnkerl/scripts/blob/master/fundam/yamm
	yamm ff2mathtest.mki
	yamm iff2mathtest.mki
	yamm ff2mathop.mki
	yamm iff2mathop.mki

install:
	make -f ff2mathtest.mk  install
	make -f iff2mathtest.mk install
	make -f ff2mathop.mk    install
	make -f iff2mathop.mk   install

clean:
	make -f ff2mathtest.mk  clean
	make -f iff2mathtest.mk clean
	make -f ff2mathop.mk    clean
	make -f iff2mathop.mk   clean
