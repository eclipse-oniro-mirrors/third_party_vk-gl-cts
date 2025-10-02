/*
 * Copyright (c) 2022 Shenzhen Kaihong Digital Industry Development Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cstdio>
#include <iostream>
#include "tcuDefs.hpp"
#include "tcuCommandLine.hpp"
#include "tcuPlatform.hpp"
#include "tcuApp.hpp"
#include "tcuResource.hpp"
#include "tcuTestLog.hpp"
#include "tcuTestSessionExecutor.hpp"
#include "deUniquePtr.hpp"

#include "external/openglcts/modules/common/glcConfigPackage.hpp"
#include "external/openglcts/modules/common/glcTestPackage.hpp"
#include "external/openglcts/modules/common/glcSingleConfigTestPackage.hpp"
#include "external/openglcts/modules/gles2/es2cTestPackage.hpp"
#include "external/openglcts/modules/gles3/es3cTestPackage.hpp"
#include "external/openglcts/modules/gles32/es32cTestPackage.hpp"
#include "external/openglcts/modules/gles31/es31cTestPackage.hpp"
#include "external/openglcts/modules/gl/gl3cTestPackages.hpp"
#include "external/openglcts/modules/gl/gl4cTestPackages.hpp"

#include "modules/egl/teglTestPackage.hpp"
#include "modules/gles2/tes2TestPackage.hpp"
#include "modules/gles3/tes3TestPackage.hpp"
#include "modules/gles3/tgl45es3TestPackage.hpp"
#include "modules/gles31/tes31TestPackage.hpp"
#include "modules/gles31/tgl45es31TestPackage.hpp"

#if defined(DEQP_GTF_AVAILABLE)
#include "gtfGL30TestPackage.hpp"
#include "gtfGL31TestPackage.hpp"
#include "gtfGL32TestPackage.hpp"
#include "gtfGL33TestPackage.hpp"
#include "gtfGL40TestPackage.hpp"
#include "gtfGL41TestPackage.hpp"
#include "gtfGL42TestPackage.hpp"
#include "gtfGL43TestPackage.hpp"
#include "gtfGL44TestPackage.hpp"
#include "gtfGL45TestPackage.hpp"
#include "gtfGL46TestPackage.hpp"
#endif

#include "ohos_context_i.h"

#include "tcuTestContext.hpp"
#include "tcuOhosPlatform.hpp"

static tcu::TestPackage *createES2Package(tcu::TestContext &testCtx)
{
    return new es2cts::TestPackage(testCtx, "KHR-GLES2");
}

static tcu::TestPackage *createES32Package(tcu::TestContext &testCtx)
{
    return new es32cts::ES32TestPackage(testCtx, "KHR-GLES32");
}
static tcu::TestPackage* createES30Package(tcu::TestContext& testCtx)
{
	return new es3cts::ES30TestPackage(testCtx, "KHR-GLES3");
}
static tcu::TestPackage* createES31Package(tcu::TestContext& testCtx)
{
	return new es31cts::ES31TestPackage(testCtx, "KHR-GLES31");
}

static tcu::TestPackage* createdEQPGL45ES31Package(tcu::TestContext& testCtx)
{
	return new deqp::gles31::TestPackageGL45ES31(testCtx);
}
static tcu::TestPackage* createdEQPGL45ES3Package(tcu::TestContext& testCtx)
{
	return new deqp::gles3::TestPackageGL45ES3(testCtx);
}

#if defined(DEQP_GTF_AVAILABLE)
static tcu::TestPackage* createES2GTFPackage(tcu::TestContext& testCtx)
{
	return new gtf::es2::TestPackage(testCtx, "GTF-GLES2");
}
#endif

#if defined(DEQP_GTF_AVAILABLE)
static tcu::TestPackage* createES30GTFPackage(tcu::TestContext& testCtx)
{
	return new gtf::es3::TestPackage(testCtx, "GTF-GLES3");
}
#endif

#if defined(DEQP_GTF_AVAILABLE)
static tcu::TestPackage* createES31GTFPackage(tcu::TestContext& testCtx)
{
	return new gtf::es31::TestPackage(testCtx, "GTF-GLES31");
}
#endif

static tcu::TestPackage* createdEQPES2Package(tcu::TestContext& testCtx)
{
	return new deqp::gles2::TestPackage(testCtx);
}
static tcu::TestPackage* createdEQPES30Package(tcu::TestContext& testCtx)
{
	return new deqp::gles3::TestPackage(testCtx);
}
static tcu::TestPackage* createdEQPES31Package(tcu::TestContext& testCtx)
{
	return new deqp::gles31::TestPackage(testCtx);
}
static tcu::TestPackage* createdEQPEGLPackage(tcu::TestContext& testCtx)
{
       return new deqp::egl::TestPackage(testCtx);
}

static tcu::TestPackage* createSingleConfigGL43TestPackage(tcu::TestContext& testCtx)
{
	return new glcts::SingleConfigGL43TestPackage(testCtx, "KHR-Single-GL43");
}
static tcu::TestPackage* createSingleConfigGL44TestPackage(tcu::TestContext& testCtx)
{
	return new glcts::SingleConfigGL44TestPackage(testCtx, "KHR-Single-GL44");
}
static tcu::TestPackage* createSingleConfigGL45TestPackage(tcu::TestContext& testCtx)
{
	return new glcts::SingleConfigGL45TestPackage(testCtx, "KHR-Single-GL45");
}
static tcu::TestPackage* createSingleConfigGL46TestPackage(tcu::TestContext& testCtx)
{
	return new glcts::SingleConfigGL45TestPackage(testCtx, "KHR-Single-GL46");
}
static tcu::TestPackage* createSingleConfigES32TestPackage(tcu::TestContext& testCtx)
{
	return new glcts::SingleConfigES32TestPackage(testCtx, "KHR-Single-GLES32");
}

static tcu::TestPackage* createGL30Package(tcu::TestContext& testCtx)
{
	return new gl3cts::GL30TestPackage(testCtx, "KHR-GL30");
}
static tcu::TestPackage* createGL31Package(tcu::TestContext& testCtx)
{
	return new gl3cts::GL31TestPackage(testCtx, "KHR-GL31");
}
static tcu::TestPackage* createGL32Package(tcu::TestContext& testCtx)
{
	return new gl3cts::GL32TestPackage(testCtx, "KHR-GL32");
}
static tcu::TestPackage* createGL33Package(tcu::TestContext& testCtx)
{
	return new gl3cts::GL33TestPackage(testCtx, "KHR-GL33");
}

static tcu::TestPackage* createGL40Package(tcu::TestContext& testCtx)
{
	return new gl4cts::GL40TestPackage(testCtx, "KHR-GL40");
}
static tcu::TestPackage* createGL41Package(tcu::TestContext& testCtx)
{
	return new gl4cts::GL41TestPackage(testCtx, "KHR-GL41");
}
static tcu::TestPackage* createGL42Package(tcu::TestContext& testCtx)
{
	return new gl4cts::GL42TestPackage(testCtx, "KHR-GL42");
}
static tcu::TestPackage* createGL42CompatPackage(tcu::TestContext& testCtx)
{
	return new gl4cts::GL42CompatTestPackage(testCtx, "KHR-GL42-COMPAT");
}
static tcu::TestPackage* createGL43Package(tcu::TestContext& testCtx)
{
	return new gl4cts::GL43TestPackage(testCtx, "KHR-GL43");
}
static tcu::TestPackage* createGL44Package(tcu::TestContext& testCtx)
{
	return new gl4cts::GL44TestPackage(testCtx, "KHR-GL44");
}
static tcu::TestPackage* createGL45Package(tcu::TestContext& testCtx)
{
	return new gl4cts::GL45TestPackage(testCtx, "KHR-GL45");
}
static tcu::TestPackage* createGL46Package(tcu::TestContext& testCtx)
{
	return new gl4cts::GL46TestPackage(testCtx, "KHR-GL46");
}

#if defined(DEQP_GTF_AVAILABLE)
static tcu::TestPackage* createGL30GTFPackage(tcu::TestContext& testCtx)
{
	return new gtf::gl30::TestPackage(testCtx, "GTF-GL30");
}
static tcu::TestPackage* createGL31GTFPackage(tcu::TestContext& testCtx)
{
	return new gtf::gl31::TestPackage(testCtx, "GTF-GL31");
}
static tcu::TestPackage* createGL32GTFPackage(tcu::TestContext& testCtx)
{
	return new gtf::gl32::TestPackage(testCtx, "GTF-GL32");
}
static tcu::TestPackage* createGL33GTFPackage(tcu::TestContext& testCtx)
{
	return new gtf::gl32::TestPackage(testCtx, "GTF-GL33");
}

static tcu::TestPackage* createGL40GTFPackage(tcu::TestContext& testCtx)
{
	return new gtf::gl40::TestPackage(testCtx, "GTF-GL40");
}
static tcu::TestPackage* createGL41GTFPackage(tcu::TestContext& testCtx)
{
	return new gtf::gl41::TestPackage(testCtx, "GTF-GL41");
}
static tcu::TestPackage* createGL42GTFPackage(tcu::TestContext& testCtx)
{
	return new gtf::gl42::TestPackage(testCtx, "GTF-GL42");
}
static tcu::TestPackage* createGL43GTFPackage(tcu::TestContext& testCtx)
{
	return new gtf::gl43::TestPackage(testCtx, "GTF-GL43");
}
static tcu::TestPackage* createGL44GTFPackage(tcu::TestContext& testCtx)
{
	return new gtf::gl44::TestPackage(testCtx, "GTF-GL44");
}
static tcu::TestPackage* createGL45GTFPackage(tcu::TestContext& testCtx)
{
	return new gtf::gl45::TestPackage(testCtx, "GTF-GL45");
}
static tcu::TestPackage* createGL46GTFPackage(tcu::TestContext& testCtx)
{
	return new gtf::gl46::TestPackage(testCtx, "GTF-GL46");
}
#endif

// Implement this in your platform port.

void RegistPackage()
{

    tcu::TestPackageRegistry *registry = tcu::TestPackageRegistry::getSingleton();
    // registry->registerPackage("CTS-Configs", createConfigPackage);

    // TODO: 判断当前上下文EGL环境是哪个?
    /*
KHR-GLES2
KHR-GLES3
KHR-GLES31
KHR-GLESEXT
KHR-GLES32
    */
    // OHOS::Rosen::RosenContext::GetInstance().GetGlesVer() == 3.2
    registry->registerPackage("KHR-GLES31", createES31Package);
    registry->registerPackage("KHR-GLES2", createES2Package);
    registry->registerPackage("KHR-GLES3", createES30Package);
    registry->registerPackage("KHR-GLES32", createES32Package);
    registry->registerPackage("dEQP-GLES2", createdEQPES2Package);
    registry->registerPackage("dEQP-GLES3", createdEQPES30Package);
    registry->registerPackage("dEQP-GLES31", createdEQPES31Package);
    registry->registerPackage("dEQP-EGL", createdEQPEGLPackage);
    registry->registerPackage("KHR-GL30", createGL30Package);
    registry->registerPackage("KHR-GL31", createGL31Package);
	registry->registerPackage("KHR-GL32", createGL32Package);
	registry->registerPackage("KHR-GL33", createGL33Package);
	registry->registerPackage("KHR-GL40", createGL40Package);
	registry->registerPackage("KHR-GL41", createGL41Package);
	registry->registerPackage("KHR-GL42", createGL42Package);
	registry->registerPackage("KHR-COMPAT-GL42", createGL42CompatPackage);
	registry->registerPackage("KHR-GL43", createGL43Package);
	registry->registerPackage("KHR-GL44", createGL44Package);
	registry->registerPackage("KHR-GL45", createGL45Package);
	registry->registerPackage("KHR-GL46", createGL46Package);
    #if defined(DEQP_GTF_AVAILABLE)
	registry->registerPackage("GTF-GLES2", createES2GTFPackage);
    registry->registerPackage("GTF-GLES3", createES30GTFPackage);
    registry->registerPackage("GTF-GLES31", createES31GTFPackage);
    registry->registerPackage("GTF-GL30", createGL30GTFPackage);
	registry->registerPackage("GTF-GL31", createGL31GTFPackage);
	registry->registerPackage("GTF-GL32", createGL32GTFPackage);
	registry->registerPackage("GTF-GL33", createGL33GTFPackage);

	registry->registerPackage("GTF-GL40", createGL40GTFPackage);
	registry->registerPackage("GTF-GL41", createGL41GTFPackage);
	registry->registerPackage("GTF-GL42", createGL42GTFPackage);
	registry->registerPackage("GTF-GL43", createGL43GTFPackage);
	registry->registerPackage("GTF-GL44", createGL44GTFPackage);
	registry->registerPackage("GTF-GL45", createGL45GTFPackage);
	registry->registerPackage("GTF-GL46", createGL46GTFPackage);
    #endif
	registry->registerPackage("dEQP-GL45-GLES31", createdEQPGL45ES31Package);
	registry->registerPackage("dEQP-GL45-GLES3", createdEQPGL45ES3Package);
	registry->registerPackage("KHR-Single-GL43", createSingleConfigGL43TestPackage);
	registry->registerPackage("KHR-Single-GL44", createSingleConfigGL44TestPackage);
	registry->registerPackage("KHR-Single-GL45", createSingleConfigGL45TestPackage);
	registry->registerPackage("KHR-Single-GL46", createSingleConfigGL46TestPackage);
	registry->registerPackage("KHR-Single-GLES32", createSingleConfigES32TestPackage);
}

bool GetCasePath(tcu::TestNode *node, std::vector<tcu::TestNode *> &casePath, std::vector<std::string> &namePath, uint32_t deep = 0)
{
    if (deep >= namePath.size())
        return false;
    if (namePath[deep].compare(node->getName()) != 0)
        return false;
    casePath.push_back(node);
    switch (node->getNodeType())
    {
    case tcu::NODETYPE_ROOT: // = 0,		//!< Root for all test packages.
        printf("NODETYPE_ROOT\n");
        break;
    case tcu::NODETYPE_PACKAGE: //,		//!< Test case package -- same as group, but is omitted from XML dump.
    case tcu::NODETYPE_GROUP: //,			//!< Test case container -- cannot be executed.
        printf("NODETYPE_GROUP\n");
        {
            std::vector<tcu::TestNode *> children;
            node->getChildren(children);
            for (uint32_t i = 0; i < children.size(); i++)
            {
                // printf("-----------%s==%s\n",children[i]->getName(),namePath[deep+1].c_str());
                if (GetCasePath(children[i], casePath, namePath, deep + 1))
                    return true;
            }
        }
        break;
    case tcu::NODETYPE_SELF_VALIDATE: //,	//!< Self-validating test case -- can be executed
        printf("NODETYPE_SELF_VALIDATE\n");
        return true;
    case tcu::NODETYPE_PERFORMANCE: //,	//!< Performace test case -- can be executed
        printf("NODETYPE_PERFORMANCE\n");
        return true;
    case tcu::NODETYPE_CAPABILITY: //,	//!< Capability score case -- can be executed
        printf("NODETYPE_CAPABILITY\n");
        return true;
    case tcu::NODETYPE_ACCURACY: //		//!< Accuracy test case -- can be executed
        printf("NODETYPE_ACCURACY\n");
        return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    printf("testmain start --- \n");
    setenv("NEED_OPENG" , "1", 1);
    setenv("LD_LIBRARY_PATH", "/system/lib64/:/system/lib64/ndk", 1);
    int exitStatus = EXIT_SUCCESS;

#if (DE_OS != DE_OS_WIN32)
    // Set stdout to line-buffered mode (will be fully buffered by default if stdout is pipe).
    setvbuf(stdout, DE_NULL, _IOLBF, 4 * 1024);
#endif

    try
    {
        RegistPackage();

        tcu::CommandLine cmdLine(argc, argv);
        tcu::DirArchive archive(cmdLine.getArchiveDir());
        tcu::TestLog log(cmdLine.getLogFileName(), cmdLine.getLogFlags());
        de::UniquePtr<tcu::Platform> platform(createOhosPlatform());
        de::UniquePtr<tcu::App> app(new tcu::App(*platform, archive, log, cmdLine));

        // Main loop.
        for (;;)
        {
            if (!app->iterate())
            {
                if (cmdLine.getRunMode() == tcu::RUNMODE_EXECUTE &&
                    (!app->getResult().isComplete || app->getResult().numFailed))
                {
                    exitStatus = EXIT_FAILURE;
                }

                break;
            }
        }
    }
    catch (const std::exception &e)
    {
        tcu::die("%s", e.what());
    }

    return exitStatus;
}