target("Specs.Interfaces")
    set_kind("headeronly")
    add_includedirs("include", { public = true })

    make_module_target("Specs.Interfaces.Module")