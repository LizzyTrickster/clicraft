
%define dist %(/usr/lib/rpm/redhat/dist.sh)
%define rhel %(/usr/lib/rpm/redhat/dist.sh --distnum)

Name:       clicraft
Version:    0.0.11
Release:    1%{?dist}
BuildArch:  noarch
Summary:    A command-line wrapper for a minecraft or bukkit server.
#wget -O SOURCES/clicraft-$version-src.tar.gz https://github.com/DMBuce/clicraft/archive/$version.tar.gz
Source0:    %{name}-%{version}-src.tar.gz
Group:      System Environment/Daemons
BuildRoot:  %{_tmppath}/%{name}-%{version}
License:    BSD

Requires:      bash, tmux, curl, java
BuildRequires: asciidoc, autoconf, libxslt-devel, docbook-style-xsl, redhat-rpm-config

%description
A command-line wrapper for a minecraft or bukkit server.

%prep
%setup -q

%build
%if %{rhel} == 5
sed -i 's/--no-xmllint//' doc/Makefile.inc
%endif
./configure --prefix=/usr \
            --sysconfdir=%{_sysconfdir} \
            --localstatedir=/var \
            --mandir=/usr/share/man
make DESTDIR=$RPM_BUILD_ROOT

%install
make DESTDIR=$RPM_BUILD_ROOT install

%clean
rm -rf %{buildroot}

%files
%defattr(-,root,root,-)
%config(noreplace) %{_sysconfdir}
%doc README.asciidoc
%doc LICENSE
%{_bindir}/%{name}
%{_libexecdir}/%{name}
%{_mandir}/man1/*.1.gz
%{_mandir}/man5/*.5.gz
%dir %{_localstatedir}/lib/%{name}

%changelog

