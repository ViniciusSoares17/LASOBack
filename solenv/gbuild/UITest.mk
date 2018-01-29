# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t -*-
#
# This file is part of the LibreOffice project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

# UITest class

gb_UITest_UNITTESTFAILED ?= $(GBUILDDIR)/platform/unittest-failed-default.sh

ifeq ($(SYSTEM_PYTHON),)
gb_UITest_EXECUTABLE := $(gb_Python_INSTALLED_EXECUTABLE)
gb_UITest_EXECUTABLE_GDB := $(gb_Python_INSTALLED_EXECUTABLE_GDB)
gb_UITest_DEPS ?= $(call gb_Package_get_target,python3)
else
gb_UITest_EXECUTABLE := $(PYTHON_FOR_BUILD)
gb_UITest_EXECUTABLE_GDB := $(PYTHON_FOR_BUILD)
gb_UITest_DEPS :=
endif

ifneq ($(strip $(UITESTTRACE)),)
gb_UITest_GDBTRACE := --gdb
gb_UITest__interactive := $(true)
endif

gb_UITest_COMMAND := $(gb_UITest_EXECUTABLE) $(SRCDIR)/uitest/test_main.py

.PHONY : $(call gb_UITest_get_clean_target,%)
$(call gb_UITest_get_clean_target,%) :
	$(call gb_Helper_abbreviate_dirs,\
		rm -f $@ $@.log)

ifneq ($(DISABLE_PYTHON),TRUE)

.PHONY : $(call gb_UITest_get_target,%)
$(call gb_UITest_get_target,%) :| $(gb_UITest_DEPS)
	$(call gb_Output_announce,$*,$(true),UIT,2)
	$(call gb_Helper_abbreviate_dirs,\
		rm -rf $(dir $(call gb_UITest_get_target,$*)) && \
		mkdir -p $(dir $(call gb_UITest_get_target,$*)) && \
		$(if $(gb_UITest__interactive),, \
		    rm -fr $@.core && mkdir $@.core && cd $@.core && ) \
		($(gb_UITest_PRECOMMAND) \
		$(if $(G_SLICE),G_SLICE=$(G_SLICE)) \
		$(if $(GLIBCXX_FORCE_NEW),GLIBCXX_FORCE_NEW=$(GLIBCXX_FORCE_NEW)) \
		$(DEFS) \
		TEST_LIB=$(call gb_Library_get_target,test) \
		URE_BOOTSTRAP=vnd.sun.star.pathname:$(call gb_Helper_get_rcfile,$(INSTROOT)/$(LIBO_ETC_FOLDER)/fundamental) \
		PYTHONPATH="$(PYPATH)" \
		TestUserDir="$(call gb_Helper_make_url,$(dir $(call gb_UITest_get_target,$*)))" \
		PYTHONDONTWRITEBYTECODE=1 \
		$(if $(filter-out MACOSX WNT,$(OS_FOR_BUILD)),$(if $(ENABLE_HEADLESS),, \
			SAL_USE_VCLPLUGIN=svp \
		)) \
		$(gb_UITest_COMMAND) \
		--soffice=path:$(INSTROOT)/$(LIBO_BIN_FOLDER)/soffice \
		--userdir=$(call gb_Helper_make_url,$(dir $(call gb_UITest_get_target,$*))user) \
		--dir=$(SRCDIR)/uitest/$(strip $(MODULES)) \
		$(gb_UITest_GDBTRACE) \
		$(if $(gb_UITest__interactive),, \
		    > $@.log 2>&1 \
		    || ($(if $(value gb_CppunitTest_postprocess), \
				    RET=$$?; \
				    $(call gb_CppunitTest_postprocess,$(gb_UITest_EXECUTABLE_GDB),$@.core,$$RET) >> $@.log 2>&1;) \
			    cat $@.log; $(gb_UITest_UNITTESTFAILED) UI $*))))

# always use udkapi and URE services
define gb_UITest_UITest
$(call gb_UITest_get_target,$(1)) : PYPATH := $(SRCDIR)/unotest/source/python$$(gb_CLASSPATHSEP)$(INSTROOT)/$(LIBO_LIB_PYUNO_FOLDER)$(if $(filter-out $(LIBO_LIB_PYUNO_FOLDER),$(LIBO_LIB_FOLDER)),$(gb_CLASSPATHSEP)$(INSTROOT)/$(LIBO_LIB_FOLDER))
$(call gb_UITest_get_target,$(1)) : MODULES :=

$(eval $(call gb_Module_register_target,$(call gb_UITest_get_target,$(1)),$(call gb_UITest_get_clean_target,$(1))))
$(call gb_Helper_make_userfriendly_targets,$(1),UITest)

endef

define gb_UITest_set_defs
$(call gb_UITest_get_target,$(1)) : DEFS := $(2)

endef

# put the directory on the PYTHONPATH because the "unittest" loader
# mysteriously fails to load modules given as absolute path unless the $PWD is
# a prefix of the absolute path, which it is not when we go into a certain
# dir to get a core dump there
#
# gb_UITest_add_modules directory module(s)
define gb_UITest_add_modules
$(call gb_UITest_get_target,$(1)) : PYPATH := $$(PYPATH)$$(gb_CLASSPATHSEP)$(2)
$(call gb_UITest_get_target,$(1)) : MODULES += $(3)

endef

define gb_UITest_use_customtarget
$(call gb_UITest_get_target,$(1)) : $(call gb_CustomTarget_get_workdir,$(2))

endef


else # DISABLE_PYTHON

.PHONY : $(call gb_UITest_get_target,$(1))
$(call gb_UITest_get_target,%) :
	$(call gb_Output_announce,$* (skipped - no UITest),$(true),PYT,2)
	@true

define gb_UITest_UITest
$(eval $(call gb_Module_register_target,$(call gb_UITest_get_target,$(1)),$(call gb_UITest_get_clean_target,$(1))))
$(call gb_Helper_make_userfriendly_targets,$(1),UITest)

endef

gb_UITest_set_defs :=
gb_UITest_add_modules :=
gb_UITest_use_customtarget :=

endif # DISABLE_PYTHON
# vim: set noet sw=4: